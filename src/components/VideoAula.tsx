import { PlayCircle, Clock } from "lucide-react";

function videoEmbedUrl(url: string): string | null {
  const watchMatch = url.match(/(?:youtube\.com\/watch\?v=|youtu\.be\/)([\w-]+)/);
  if (watchMatch) return `https://www.youtube.com/embed/${watchMatch[1]}`;
  return null;
}

export function VideoAula({
  url,
  titulo,
  className = "mb-8",
}: {
  url?: string;
  titulo: string;
  className?: string;
}) {
  if (!url) {
    return (
      <div
        className={`flex aspect-video w-full flex-col items-center justify-center gap-2 rounded-lg border border-dashed border-border bg-bg-card text-center ${className}`}
      >
        <Clock className="size-7 text-fg-faint" />
        <p className="text-sm text-fg-faint">
          Vídeo-aula ainda não gravada — em breve por aqui.
        </p>
      </div>
    );
  }

  const embedUrl = videoEmbedUrl(url);

  if (!embedUrl) {
    return (
      <a
        href={url}
        target="_blank"
        rel="noreferrer"
        className={`flex items-center gap-2 text-sm text-accent-soft hover:underline ${className}`}
      >
        <PlayCircle className="size-4" />
        Assistir vídeo-aula
      </a>
    );
  }

  return (
    <div
      className={`aspect-video w-full overflow-hidden rounded-lg border border-border shadow-lg shadow-black/30 ${className}`}
    >
      <iframe
        src={embedUrl}
        title={`Vídeo-aula: ${titulo}`}
        className="h-full w-full"
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture"
        allowFullScreen
      />
    </div>
  );
}
