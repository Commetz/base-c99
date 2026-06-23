import { BookOpen, Code2, Video, Users } from "lucide-react";

const FEATURES = [
  {
    icon: BookOpen,
    titulo: "Aulas guiadas",
    descricao:
      "Do zero até ponteiros e alocação dinâmica, em uma trilha pensada para calouros — sem pular etapas.",
  },
  {
    icon: Code2,
    titulo: "Exercícios resolvidos",
    descricao:
      "Soluções comentadas do Beecrowd, organizadas por categoria e nível de dificuldade.",
  },
  {
    icon: Video,
    titulo: "Vídeo-aulas",
    descricao:
      "Cada exercício terá uma explicação em vídeo, focada na lógica por trás da solução — não só o código pronto.",
  },
  {
    icon: Users,
    titulo: "Feito por quem já passou por isso",
    descricao:
      "Projeto de extensão da UNIOESTE, criado por alunos para ajudar quem está começando agora.",
  },
];

export function Features() {
  return (
    <section className="border-b border-border bg-bg-raised/40">
      <div className="mx-auto max-w-6xl px-5 py-16 md:py-20">
        <p className="mb-2 font-mono text-xs tracking-widest text-accent">
          O QUE VOCÊ ENCONTRA AQUI
        </p>
        <h2 className="mb-10 max-w-lg font-display text-2xl font-semibold tracking-tight text-fg md:text-3xl">
          Tudo o que um calouro precisa para sair do zero em C.
        </h2>

        <div className="grid gap-4 sm:grid-cols-2 lg:grid-cols-4">
          {FEATURES.map(({ icon: Icon, titulo, descricao }) => (
            <div
              key={titulo}
              className="rounded-lg border border-border bg-bg-card p-5 transition-colors hover:border-support"
            >
              <div className="mb-3 flex size-9 items-center justify-center rounded-md bg-accent/10">
                <Icon className="size-4.5 text-accent-soft" />
              </div>
              <h3 className="mb-1.5 font-display text-base font-semibold text-fg">
                {titulo}
              </h3>
              <p className="text-sm leading-relaxed text-fg-muted">
                {descricao}
              </p>
            </div>
          ))}
        </div>
      </div>
    </section>
  );
}
