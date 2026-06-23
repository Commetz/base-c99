"use client";

import Link from "next/link";
import { usePathname } from "next/navigation";
import type { AulaMeta } from "@/lib/aulas";

export function AulaTabs({ aulas }: { aulas: AulaMeta[] }) {
  const pathname = usePathname();

  return (
    <nav
      aria-label="Navegação entre aulas"
      className="flex flex-wrap gap-1.5 border-b border-border pb-5"
    >
      {aulas.map((aula) => {
        const href = `/aulas/${aula.slug}`;
        const active = pathname === href;
        return (
          <Link
            key={aula.slug}
            href={href}
            className={`group flex items-center gap-2 rounded-md border px-3 py-1.5 text-sm font-medium transition-all ${
              active
                ? "border-accent-dim bg-accent/10 text-accent-soft"
                : "border-transparent text-fg-muted hover:border-border hover:bg-bg-card hover:text-fg"
            }`}
          >
            {aula.titulo === "Introdução" ? "Intro" : `Aula ${aula.ordem}`}
          </Link>
        );
      })}
    </nav>
  );
}
