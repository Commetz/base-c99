import { listarAulasMeta } from "@/lib/aulas";
import { contarExerciciosTotais } from "@/lib/exercicios";
import { CATEGORIAS } from "@/lib/categorias";

export function Estatisticas() {
  const totalAulas = listarAulasMeta().filter((a) => a.slug !== "intro").length;
  const totalExercicios = contarExerciciosTotais();
  const totalCategorias = CATEGORIAS.length;

  const itens = [
    { valor: String(totalAulas), label: "aulas guiadas" },
    { valor: String(totalExercicios), label: "exercícios resolvidos" },
    { valor: String(totalCategorias), label: "categorias" },
    { valor: "Grátis", label: "para sempre" },
  ];

  return (
    <section className="border-b border-border">
      <div className="mx-auto max-w-6xl px-5 py-12 md:py-16">
        <div className="grid grid-cols-2 gap-px overflow-hidden rounded-lg border border-border bg-border sm:grid-cols-4">
          {itens.map((item) => (
            <div
              key={item.label}
              className="flex flex-col gap-1 bg-bg px-6 py-7 text-center"
            >
              <span className="font-display text-3xl font-semibold text-accent-soft md:text-4xl">
                {item.valor}
              </span>
              <span className="text-xs text-fg-muted">{item.label}</span>
            </div>
          ))}
        </div>
      </div>
    </section>
  );
}
