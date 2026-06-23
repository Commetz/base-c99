import { notFound } from "next/navigation";
import type { Metadata } from "next";
import { CATEGORIAS, getCategoria } from "@/lib/categorias";
import { listarExercicios } from "@/lib/exercicios";
import { ExercicioExplorer } from "@/components/ExercicioExplorer";

export async function generateStaticParams() {
  return CATEGORIAS.map((c) => ({ categoria: c.slug }));
}

export async function generateMetadata({
  params,
}: {
  params: Promise<{ categoria: string }>;
}): Promise<Metadata> {
  const { categoria } = await params;
  const cat = getCategoria(categoria);
  return {
    title: cat ? `${cat.nome} — Base C` : "Exercícios — Base C",
  };
}

export default async function CategoriaPage({
  params,
}: {
  params: Promise<{ categoria: string }>;
}) {
  const { categoria } = await params;
  const cat = getCategoria(categoria);
  if (!cat) notFound();

  const exercicios = listarExercicios(categoria);

  return (
    <section className="mx-auto max-w-5xl px-5 py-10">
      <div className="mb-8 flex flex-wrap gap-1.5">
        {CATEGORIAS.map((c) => (
          <a
            key={c.slug}
            href={`/exercicios/${c.slug}`}
            className={`rounded-md border px-3 py-1.5 text-sm font-medium transition-colors ${
              c.slug === categoria
                ? "border-accent-dim bg-accent/10 text-accent-soft"
                : "border-transparent text-fg-muted hover:border-border hover:bg-bg-card hover:text-fg"
            }`}
          >
            {c.nome}
          </a>
        ))}
      </div>

      <div className="mb-6 flex items-baseline gap-3">
        <h1 className="font-display text-2xl font-semibold tracking-tight text-fg md:text-3xl">
          {cat.nome}
        </h1>
      </div>
      <p className="mb-8 max-w-2xl text-fg-muted">{cat.descricao}</p>

      <ExercicioExplorer categoriaSlug={categoria} exercicios={exercicios} />
    </section>
  );
}
