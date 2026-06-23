"use client";

import { useEffect, useState } from "react";
import Link from "next/link";
import { ArrowRight, ListChecks } from "lucide-react";

const CODIGO = [
  { texto: "#include <stdio.h>", cor: "text-support-soft" },
  { texto: "", cor: "" },
  { texto: "int main(void) {", cor: "text-fg" },
  { texto: '    printf("Olá, Calouro!\\n");', cor: "text-fg", destaque: true },
  { texto: "    return 0;", cor: "text-fg" },
  { texto: "}", cor: "text-fg" },
];

const VELOCIDADE_DIGITACAO = 28; // ms por caractere

/**
 * Separa uma linha tipo `    printf("...");` em três partes:
 * [prefixo até o "(", a string entre aspas (incluindo as aspas), o que vem depois]
 * Funciona corretamente também com a string ainda incompleta (durante a digitação).
 */
function separarStringPrintf(
  textoVisivel: string
): [string, string, string] | null {
  const m = textoVisivel.match(/^(\s*printf\()(.*)$/);
  if (!m) return null;

  const prefixo = m[1];
  const resto = m[2];

  const aberturaIdx = resto.indexOf('"');
  if (aberturaIdx === -1) return [prefixo, "", resto];

  const fechamentoIdx = resto.lastIndexOf('"');
  if (fechamentoIdx > aberturaIdx) {
    const string = resto.slice(0, fechamentoIdx + 1);
    const depois = resto.slice(fechamentoIdx + 1);
    return [prefixo, string, depois];
  }

  // só a aspas de abertura digitada até agora — string ainda incompleta
  return [prefixo, resto, ""];
}

export function Hero() {
  const [linhaAtual, setLinhaAtual] = useState(0);
  const [charsNaLinha, setCharsNaLinha] = useState(0);
  const [terminado, setTerminado] = useState(false);

  useEffect(() => {
    if (linhaAtual >= CODIGO.length) {
      const t = setTimeout(() => setTerminado(true), 400);
      return () => clearTimeout(t);
    }

    const linha = CODIGO[linhaAtual].texto;

    if (charsNaLinha < linha.length) {
      const t = setTimeout(
        () => setCharsNaLinha((c) => c + 1),
        VELOCIDADE_DIGITACAO
      );
      return () => clearTimeout(t);
    }

    // linha terminada, pequena pausa antes da próxima
    const t = setTimeout(() => {
      setLinhaAtual((l) => l + 1);
      setCharsNaLinha(0);
    }, 180);
    return () => clearTimeout(t);
  }, [linhaAtual, charsNaLinha]);

  return (
    <section className="bg-grain border-b border-border">
      <div className="mx-auto grid max-w-6xl gap-12 px-5 py-16 md:grid-cols-2 md:items-center md:py-24">
        <div>
          <p className="mb-4 font-mono text-xs tracking-widest text-accent">
            EXTENSÃO UNIOESTE · CASCAVEL
          </p>
          <h1 className="font-display text-4xl font-semibold italic leading-[1.1] tracking-tight text-fg md:text-5xl">
            A base de C que{" "}
            <span className="text-accent-soft not-italic">todo calouro</span>{" "}
            devia ter.
          </h1>
          <p className="mt-5 max-w-md text-base leading-relaxed text-fg-muted">
            Aulas guiadas do zero até ponteiros e alocação dinâmica, mais um
            repositório vivo de exercícios do Beecrowd resolvidos em C99,
            organizados por categoria.
          </p>
          <div className="mt-8 flex flex-wrap items-center gap-3">
            <Link
              href="/aulas/intro"
              className="inline-flex items-center gap-2 rounded-md bg-accent px-4 py-2.5 text-sm font-semibold text-bg transition-transform hover:translate-y-[-1px] hover:bg-accent-soft"
            >
              Começar pela Aula 1
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

        <div className="rounded-lg border border-border bg-bg-raised shadow-2xl shadow-black/40">
          <div className="flex items-center gap-2 border-b border-border px-4 py-2.5">
            <span className="size-2.5 rounded-full bg-danger/70" />
            <span className="size-2.5 rounded-full bg-accent/70" />
            <span className="size-2.5 rounded-full bg-ok/70" />
            <span className="ml-2 font-mono text-xs text-fg-faint">
              aula01.c
            </span>
          </div>
          <pre className="overflow-x-auto p-5 font-mono text-sm leading-relaxed text-fg-muted">
            <code>
              {CODIGO.map((linha, i) => {
                if (i > linhaAtual) return null;
                const textoVisivel =
                  i === linhaAtual
                    ? linha.texto.slice(0, charsNaLinha)
                    : linha.texto;

                if (linha.destaque) {
                  const partes = separarStringPrintf(textoVisivel);
                  return (
                    <div key={i} className={linha.cor}>
                      {partes ? (
                        <>
                          {partes[0]}
                          <span className="text-ok">{partes[1]}</span>
                          {partes[2]}
                        </>
                      ) : (
                        textoVisivel
                      )}
                      {i === linhaAtual && !terminado && (
                        <span className="animate-pulse text-accent">▏</span>
                      )}
                    </div>
                  );
                }

                return (
                  <div key={i} className={linha.cor || undefined}>
                    {textoVisivel || "\u00a0"}
                    {i === linhaAtual && !terminado && (
                      <span className="animate-pulse text-accent">▏</span>
                    )}
                  </div>
                );
              })}
            </code>
          </pre>
          <div className="border-t border-border px-5 py-3 font-mono text-xs">
            {terminado ? (
              <span className="text-accent-soft">
                $ gcc aula01.c -o aula01 && ./aula01
                <br />
                Olá, Calouro!
              </span>
            ) : (
              <span className="text-fg-faint">compilando…</span>
            )}
          </div>
        </div>
      </div>
    </section>
  );
}
