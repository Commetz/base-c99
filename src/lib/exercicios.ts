import fs from "fs";
import path from "path";
import { CATEGORIAS, getCategoria, type Dificuldade } from "./categorias";

const CONTENT_DIR = path.join(process.cwd(), "content", "exercicios");
const META_PATH = path.join(process.cwd(), "content", "exercicios-meta.json");

export type ExercicioMeta = {
  tags?: string[];
  descricao?: string;
  dificuldade?: Dificuldade;
  video?: string;
};

export type Exercicio = {
  numero: string;
  arquivo: string;
  categoria: string;
  titulo: string;
  dificuldade: Dificuldade;
  tags: string[];
  descricao: string | null;
  video: string | null;
};

let metaCache: Record<string, ExercicioMeta> | null = null;

function carregarMeta(): Record<string, ExercicioMeta> {
  if (metaCache) return metaCache;
  try {
    const raw = fs.readFileSync(META_PATH, "utf-8");
    const data = JSON.parse(raw);
    delete data._comentario;
    metaCache = data;
  } catch {
    metaCache = {};
  }
  return metaCache!;
}

/**
 * Extrai um título legível a partir do comentário de cabeçalho do arquivo .c.
 * Convenção usada no projeto: "// 1002 Beecrowd - Área Do Círculo"
 */
function extrairTitulo(conteudo: string, numero: string): string {
  const primeiraLinha = conteudo.split("\n")[0] ?? "";
  const match = primeiraLinha.match(/Beecrowd\s*-\s*(.+)/i);
  if (match) return match[1].trim();
  return `Exercício ${numero}`;
}

function montarExercicio(
  categoriaSlug: string,
  arquivo: string,
  conteudo: string
): Exercicio {
  const numero = arquivo.replace(".c", "");
  const categoria = getCategoria(categoriaSlug);
  const meta = carregarMeta()[`${categoriaSlug}/${numero}`] ?? {};

  return {
    numero,
    arquivo,
    categoria: categoriaSlug,
    titulo: extrairTitulo(conteudo, numero),
    dificuldade: meta.dificuldade ?? categoria?.dificuldadePadrao ?? "medio",
    tags: meta.tags ?? [],
    descricao: meta.descricao ?? null,
    video: meta.video ?? null,
  };
}

/**
 * Lê dinamicamente os arquivos .c de uma categoria.
 * Basta adicionar um novo arquivo .c na pasta correspondente —
 * não é necessário editar nenhum array manualmente.
 */
export function listarExercicios(categoriaSlug: string): Exercicio[] {
  const dirPath = path.join(CONTENT_DIR, categoriaSlug);
  if (!fs.existsSync(dirPath)) return [];

  const arquivos = fs
    .readdirSync(dirPath)
    .filter((f) => f.endsWith(".c"))
    .sort((a, b) => a.localeCompare(b, undefined, { numeric: true }));

  return arquivos.map((arquivo) => {
    const conteudo = fs.readFileSync(path.join(dirPath, arquivo), "utf-8");
    return montarExercicio(categoriaSlug, arquivo, conteudo);
  });
}

export function getExercicio(
  categoriaSlug: string,
  arquivo: string
): Exercicio | null {
  const nomeSeguro = path.basename(arquivo);
  const filePath = path.join(CONTENT_DIR, categoriaSlug, nomeSeguro);
  if (!fs.existsSync(filePath)) return null;
  const conteudo = fs.readFileSync(filePath, "utf-8");
  return montarExercicio(categoriaSlug, nomeSeguro, conteudo);
}

export function lerCodigoExercicio(
  categoriaSlug: string,
  arquivo: string
): string | null {
  const nomeSeguro = path.basename(arquivo);
  const filePath = path.join(CONTENT_DIR, categoriaSlug, nomeSeguro);
  if (!fs.existsSync(filePath)) return null;
  return fs.readFileSync(filePath, "utf-8");
}

export function contarExerciciosTotais(): number {
  return CATEGORIAS.reduce(
    (total, cat) => total + listarExercicios(cat.slug).length,
    0
  );
}
