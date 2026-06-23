import { NextResponse } from "next/server";
import { codeToHtml } from "shiki";
import { lerCodigoExercicio } from "@/lib/exercicios";
import { getCategoria } from "@/lib/categorias";

export async function GET(
  _req: Request,
  { params }: { params: Promise<{ categoria: string; arquivo: string }> }
) {
  const { categoria, arquivo } = await params;

  if (!getCategoria(categoria)) {
    return NextResponse.json({ error: "Categoria inválida" }, { status: 404 });
  }

  const codigo = lerCodigoExercicio(categoria, arquivo);

  if (codigo === null) {
    return NextResponse.json(
      { error: "Exercício não encontrado" },
      { status: 404 }
    );
  }

  const html = await codeToHtml(codigo, {
    lang: "c",
    theme: "github-dark-default",
  });

  return NextResponse.json({ codigo, html });
}
