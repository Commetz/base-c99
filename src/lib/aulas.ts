import fs from "fs";
import path from "path";
import matter from "gray-matter";
import { unified } from "unified";
import remarkParse from "remark-parse";
import remarkGfm from "remark-gfm";
import remarkRehype from "remark-rehype";
import rehypePrettyCode from "rehype-pretty-code";
import rehypeStringify from "rehype-stringify";

const AULAS_DIR = path.join(process.cwd(), "content", "aulas");

export type AulaMeta = {
  ordem: number;
  slug: string;
  titulo: string;
  endereco: string;
  video?: string;
};

export type Aula = AulaMeta & {
  html: string;
};

function getArquivosAulas(): string[] {
  return fs
    .readdirSync(AULAS_DIR)
    .filter((f) => f.endsWith(".md"))
    .sort();
}

export function listarAulasMeta(): AulaMeta[] {
  return getArquivosAulas().map((arquivo) => {
    const raw = fs.readFileSync(path.join(AULAS_DIR, arquivo), "utf-8");
    const { data } = matter(raw);
    return data as AulaMeta;
  });
}

export async function getAula(slug: string): Promise<Aula | null> {
  const arquivos = getArquivosAulas();
  const arquivo = arquivos.find((f) => f.includes(slug));
  if (!arquivo) return null;

  const raw = fs.readFileSync(path.join(AULAS_DIR, arquivo), "utf-8");
  const { data, content } = matter(raw);

  const file = await unified()
    .use(remarkParse)
    .use(remarkGfm)
    .use(remarkRehype)
    .use(rehypePrettyCode, {
      theme: "github-dark-default",
      keepBackground: false,
    })
    .use(rehypeStringify)
    .process(content);

  return {
    ...(data as AulaMeta),
    html: String(file),
  };
}

export async function getTodasAulas(): Promise<Aula[]> {
  const metas = listarAulasMeta().sort((a, b) => a.ordem - b.ordem);
  const aulas = await Promise.all(metas.map((m) => getAula(m.slug)));
  return aulas.filter((a): a is Aula => a !== null);
}
