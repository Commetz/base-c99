"use client";

import { useEffect, useRef } from "react";

/**
 * Varre o conteúdo renderizado em busca de blocos <pre> e injeta
 * um botão de copiar em cada um. Funciona sobre HTML estático
 * vindo do processamento de markdown (rehype-pretty-code).
 */
export function ConteudoAula({ html }: { html: string }) {
  const ref = useRef<HTMLDivElement>(null);

  useEffect(() => {
    const container = ref.current;
    if (!container) return;

    const blocos = container.querySelectorAll("pre");

    blocos.forEach((pre) => {
      if (pre.parentElement?.classList.contains("code-wrapper")) return;

      const wrapper = document.createElement("div");
      wrapper.className = "code-wrapper relative group";
      pre.parentNode?.insertBefore(wrapper, pre);
      wrapper.appendChild(pre);

      const btn = document.createElement("button");
      btn.type = "button";
      btn.className =
        "absolute top-2.5 right-2.5 rounded-md border border-border bg-bg-card px-2 py-1 text-xs text-fg-muted opacity-0 transition-opacity group-hover:opacity-100 hover:text-accent-soft hover:border-accent-dim";
      btn.textContent = "Copiar";

      btn.addEventListener("click", async () => {
        const text = pre.textContent ?? "";
        await navigator.clipboard.writeText(text);
        btn.textContent = "Copiado";
        setTimeout(() => (btn.textContent = "Copiar"), 1500);
      });

      wrapper.appendChild(btn);
    });
  }, [html]);

  return (
    <div
      ref={ref}
      className="prose-content"
      dangerouslySetInnerHTML={{ __html: html }}
    />
  );
}
