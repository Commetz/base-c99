import Link from "next/link";
import { ArrowRight, ListChecks } from "lucide-react";

export function CtaFinal() {
  return (
    <section className="border-b border-border bg-grain">
      <div className="mx-auto flex max-w-6xl flex-col items-start gap-6 px-5 py-16 md:flex-row md:items-center md:justify-between md:py-20">
        <div>
          <h2 className="font-display text-2xl font-semibold tracking-tight text-fg md:text-3xl">
            Pronto para começar?
          </h2>
          <p className="mt-2 max-w-md text-fg-muted">
            Siga a trilha de aulas em ordem, ou vá direto para os exercícios
            se já souber o básico.
          </p>
        </div>
        <div className="flex flex-wrap gap-3">
          <Link
            href="/aulas/intro"
            className="inline-flex items-center gap-2 rounded-md bg-accent px-4 py-2.5 text-sm font-semibold text-bg transition-transform hover:translate-y-[-1px] hover:bg-accent-soft"
          >
            Começar pelas aulas
            <ArrowRight className="size-4" />
          </Link>
          <Link
            href="/exercicios/iniciante"
            className="inline-flex items-center gap-2 rounded-md border border-border px-4 py-2.5 text-sm font-medium text-fg-muted transition-colors hover:border-support hover:text-fg"
          >
            <ListChecks className="size-4" />
            Ver exercícios
          </Link>
        </div>
      </div>
    </section>
  );
}
