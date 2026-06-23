import { GitBranch } from "lucide-react";

export function Footer() {
  return (
    <footer className="border-t border-border">
      <div className="mx-auto flex max-w-6xl flex-col gap-2 px-5 py-8 text-sm text-fg-faint sm:flex-row sm:items-center sm:justify-between">
        <p>
          Base C — projeto de extensão universitária, UNIOESTE.
        </p>
        <a
          href="https://github.com"
          target="_blank"
          rel="noreferrer"
          className="flex items-center gap-1.5 transition-colors hover:text-fg-muted"
        >
        </a>
      </div>
    </footer>
  );
}
