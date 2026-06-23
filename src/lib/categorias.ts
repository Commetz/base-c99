export type Dificuldade = "facil" | "medio" | "dificil";

export type Categoria = {
  slug: string;
  nome: string;
  descricao: string;
  endereco: string; // "endereço de memória" decorativo/temático
  dificuldadePadrao: Dificuldade;
};

export const CATEGORIAS: Categoria[] = [
  {
    slug: "iniciante",
    nome: "Iniciante",
    descricao: "Primeiros passos: entrada, saída e lógica básica.",
    endereco: "0x00",
    dificuldadePadrao: "facil",
  },
  {
    slug: "geral",
    nome: "Geral",
    descricao: "Mistura de exercícios de fundamentos diversos.",
    endereco: "0x01",
    dificuldadePadrao: "facil",
  },
  {
    slug: "adhoc",
    nome: "Ad-Hoc",
    descricao: "Problemas sem categoria fixa, exigem raciocínio direto.",
    endereco: "0x02",
    dificuldadePadrao: "dificil",
  },
  {
    slug: "strings",
    nome: "Strings",
    descricao: "Manipulação de cadeias de caracteres.",
    endereco: "0x03",
    dificuldadePadrao: "medio",
  },
  {
    slug: "matematica",
    nome: "Matemática",
    descricao: "Problemas com foco em cálculo e lógica numérica.",
    endereco: "0x04",
    dificuldadePadrao: "medio",
  },
  {
    slug: "estruturas",
    nome: "Estruturas",
    descricao: "Vetores, matrizes e estruturas de dados.",
    endereco: "0x05",
    dificuldadePadrao: "dificil",
  },
];

export function getCategoria(slug: string): Categoria | undefined {
  return CATEGORIAS.find((c) => c.slug === slug);
}

export const DIFICULDADE_LABEL: Record<Dificuldade, string> = {
  facil: "Fácil",
  medio: "Médio",
  dificil: "Difícil",
};
