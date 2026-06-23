import type { Dificuldade } from "@/lib/categorias";
import { DIFICULDADE_LABEL } from "@/lib/categorias";

const CLASSES: Record<Dificuldade, string> = {
  facil: "bg-ok/10 text-ok border-ok/30",
  medio: "bg-warn/10 text-warn border-warn/30",
  dificil: "bg-danger/10 text-danger border-danger/30",
  anomalia: "bg-gray/10 text-gray border-gray/30",
};

export function DificuldadeBadge({
  dificuldade,
  className = "",
}: {
  dificuldade: Dificuldade;
  className?: string;
}) {
  return (
    <span
      className={`inline-flex items-center rounded-full border px-2 py-0.5 text-[11px] font-medium ${CLASSES[dificuldade]} ${className}`}
    >
      {DIFICULDADE_LABEL[dificuldade]}
    </span>
  );
}
