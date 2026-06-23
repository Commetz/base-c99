"use client";

import { useMemo, useState } from "react";
import {
  Search,
  Copy,
  Check,
  FileCode,
  ExternalLink,
  PlayCircle,
  Code2,
} from "lucide-react";
import type { Exercicio } from "@/lib/exercicios";
import { DificuldadeBadge } from "@/components/DificuldadeBadge";
import { VideoAula } from "@/components/VideoAula";

type Aba = "aula" | "codigo";

export function ExercicioExplorer({
  categoriaSlug,
  exercicios,
}: {
  categoriaSlug: string;
  exercicios: Exercicio[];
}) {
  const [filtro, setFiltro] = useState("");
  const [selecionado, setSelecionado] = useState<Exercicio | null>(null);
  const [aba, setAba] = useState<Aba>("aula");
  const [html, setHtml] = useState<string | null>(null);
  const [codigoRaw, setCodigoRaw] = useState<string>("");
  const [carregando, setCarregando] = useState(false);
  const [copiado, setCopiado] = useState(false);

  const filtrados = useMemo(() => {
    const termo = filtro.trim().toLowerCase();
    if (!termo) return exercicios;
    return exercicios.filter(
      (ex) =>
        ex.numero.includes(termo) ||
        ex.titulo.toLowerCase().includes(termo) ||
        ex.tags.some((t) => t.toLowerCase().includes(termo))
    );
  }, [exercicios, filtro]);

  async function selecionar(ex: Exercicio) {
    setSelecionado(ex);
    setAba("aula");
    setCarregando(true);
    setHtml(null);
    try {
      const res = await fetch(
        `/api/exercicios/${categoriaSlug}/${ex.arquivo}`
      );
      const data = await res.json();
      if (res.ok) {
        setHtml(data.html);
        setCodigoRaw(data.codigo);
      }
    } finally {
      setCarregando(false);
    }
  }

  async function copiar() {
    if (!codigoRaw) return;
    await navigator.clipboard.writeText(codigoRaw);
    setCopiado(true);
    setTimeout(() => setCopiado(false), 1500);
  }

  return (
    <div className="grid gap-6 md:grid-cols-[220px_1fr]">
      {/* Sidebar: busca + lista de cards */}
      <div className="flex flex-col gap-3">
        <div className="relative">
          <Search className="pointer-events-none absolute left-3 top-1/2 size-4 -translate-y-1/2 text-fg-faint" />
          <input
            type="text"
            value={filtro}
            onChange={(e) => setFiltro(e.target.value)}
            placeholder="Buscar exercício…"
            className="w-full rounded-md border border-border bg-bg-card py-2 pl-9 pr-3 text-sm text-fg placeholder:text-fg-faint focus:border-accent-dim"
          />
        </div>

        <ul className="flex max-h-[75vh] flex-col gap-2 overflow-y-auto pr-1">
          {filtrados.length === 0 && (
            <li className="px-2 py-4 text-center text-sm text-fg-faint">
              Nenhum exercício encontrado.
            </li>
          )}
          {filtrados.map((ex) => (
            <li key={ex.arquivo}>
              <button
                onClick={() => selecionar(ex)}
                className={`flex w-full flex-col gap-1.5 rounded-lg border px-3 py-2.5 text-left transition-colors ${
                  selecionado?.arquivo === ex.arquivo
                    ? "border-accent-dim bg-accent/10"
                    : "border-border bg-bg-card hover:border-support"
                }`}
              >
                <div className="flex items-center justify-between gap-2">
                  <span className="flex items-center gap-1.5 font-mono text-xs text-fg-faint">
                    <FileCode className="size-3.5" />
                    {ex.numero}
                  </span>
                  <div className="flex items-center gap-1.5">
                    {ex.video && (
                      <PlayCircle className="size-3.5 text-accent-soft" />
                    )}
                    <DificuldadeBadge dificuldade={ex.dificuldade} />
                  </div>
                </div>
                <span
                  className={`text-sm font-medium ${
                    selecionado?.arquivo === ex.arquivo
                      ? "text-accent-soft"
                      : "text-fg"
                  }`}
                >
                  {ex.titulo}
                </span>
                {ex.tags.length > 0 && (
                  <div className="flex flex-wrap gap-1">
                    {ex.tags.map((tag) => (
                      <span
                        key={tag}
                        className="rounded bg-bg-raised px-1.5 py-0.5 text-[10px] text-fg-muted"
                      >
                        {tag}
                      </span>
                    ))}
                  </div>
                )}
              </button>
            </li>
          ))}
        </ul>
      </div>

      {/* Painel principal: vazio, ou conteúdo do exercício selecionado */}
      {!selecionado && (
        <div className="flex min-h-[450px] flex-col items-center justify-center gap-2 rounded-lg border border-border bg-bg-raised p-8 text-center text-fg-faint">
          <FileCode className="size-8" />
          <p className="text-sm">
            Selecione um exercício na lista para ver a aula e o código.
          </p>
        </div>
      )}

      {selecionado && (
        <div className="overflow-hidden rounded-lg border border-border bg-bg-raised">
          {/* Cabeçalho */}
          <div className="flex flex-wrap items-center justify-between gap-2 border-b border-border px-4 py-3">
            <div>
              <div className="flex items-center gap-2">
                <span className="font-mono text-xs text-fg-faint">
                  {selecionado.numero}
                </span>
                <DificuldadeBadge dificuldade={selecionado.dificuldade} />
              </div>
              <h3 className="mt-0.5 font-display text-base font-semibold text-fg">
                {selecionado.titulo}
              </h3>
            </div>
            <a
              href={`https://judge.beecrowd.com/pt/problems/view/${selecionado.numero}`}
              target="_blank"
              rel="noreferrer"
              className="flex shrink-0 items-center gap-1 rounded-md border border-border px-2.5 py-1.5 text-xs text-fg-muted transition-colors hover:border-accent-dim hover:text-accent-soft"
            >
              Beecrowd
              <ExternalLink className="size-3" />
            </a>
          </div>

          {/* Abas */}
          <div className="flex gap-1 border-b border-border px-3 pt-2">
            <AbaBtn
              ativa={aba === "aula"}
              onClick={() => setAba("aula")}
              icon={<PlayCircle className="size-4" />}
              label="Aula"
            />
            <AbaBtn
              ativa={aba === "codigo"}
              onClick={() => setAba("codigo")}
              icon={<Code2 className="size-4" />}
              label="Código"
            />
          </div>

          {/* Aba: Aula (vídeo grande + enunciado abaixo) */}
          {aba === "aula" && (
            <div className="p-4 md:p-5">
              <VideoAula
                url={selecionado.video ?? undefined}
                titulo={selecionado.titulo}
                className="mx-auto max-w-3xl"
              />
              <div className="mx-auto mt-5 max-w-3xl">
                <p className="mb-1.5 text-xs font-medium uppercase tracking-wide text-fg-faint">
                  Enunciado
                </p>
                <p className="text-sm leading-relaxed text-fg-muted">
                  {selecionado.descricao ?? (
                    <span className="italic text-fg-faint">
                      Resumo do enunciado ainda não cadastrado — consulte o
                      problema completo no Beecrowd.
                    </span>
                  )}
                </p>
              </div>
            </div>
          )}

          {/* Aba: Código */}
          {aba === "codigo" && (
            <div className="relative">
              <div className="flex items-center justify-between border-b border-border px-4 py-2.5">
                <span className="flex items-center gap-1.5 font-mono text-xs text-fg-muted">
                  <FileCode className="size-3.5" />
                  {selecionado.arquivo}
                </span>
                <button
                  onClick={copiar}
                  className="flex items-center gap-1 rounded-md border border-border px-2 py-1 text-xs text-fg-muted transition-colors hover:border-accent-dim hover:text-accent-soft"
                >
                  {copiado ? (
                    <>
                      <Check className="size-3" /> Copiado
                    </>
                  ) : (
                    <>
                      <Copy className="size-3" /> Copiar
                    </>
                  )}
                </button>
              </div>
              <div className="max-h-[65vh] overflow-auto p-1 text-sm [&_pre]:!my-0 [&_pre]:!rounded-none [&_pre]:!border-none">
                {carregando && (
                  <p className="p-5 text-sm text-fg-faint">Carregando…</p>
                )}
                {!carregando && html && (
                  <div dangerouslySetInnerHTML={{ __html: html }} />
                )}
              </div>
            </div>
          )}
        </div>
      )}
    </div>
  );
}

function AbaBtn({
  ativa,
  onClick,
  icon,
  label,
}: {
  ativa: boolean;
  onClick: () => void;
  icon: React.ReactNode;
  label: string;
}) {
  return (
    <button
      onClick={onClick}
      className={`flex items-center gap-1.5 rounded-t-md border-b-2 px-3.5 py-2 text-sm font-medium transition-colors ${
        ativa
          ? "border-accent text-accent-soft"
          : "border-transparent text-fg-muted hover:text-fg"
      }`}
    >
      {icon}
      {label}
    </button>
  );
}
