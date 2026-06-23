import { listarAulasMeta } from "@/lib/aulas";
import { AulaTabs } from "@/components/AulaTabs";
import { ConteudoAula } from "@/components/ConteudoAula";
import { VideoAula } from "@/components/VideoAula";
import type { Aula } from "@/lib/aulas";

export function AulaLayout({ aula }: { aula: Aula }) {
  const todasMetas = listarAulasMeta().sort((a, b) => a.ordem - b.ordem);
  const ehIntro = aula.slug === "intro";

  return (
    <section className="mx-auto max-w-3xl px-5 py-10">
      <AulaTabs aulas={todasMetas} />

      <div className="mt-8">
        <div className="mb-6 flex items-baseline gap-3">
          <h1 className="font-display text-2xl font-semibold tracking-tight text-fg md:text-3xl">
            {aula.titulo}
          </h1>
        </div>

        {!ehIntro && <VideoAula url={aula.video} titulo={aula.titulo} />}

        <ConteudoAula html={aula.html} />
      </div>
    </section>
  );
}
