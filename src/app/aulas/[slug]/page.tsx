import { getAula, listarAulasMeta } from "@/lib/aulas";
import { AulaLayout } from "@/components/AulaLayout";
import { notFound } from "next/navigation";
import type { Metadata } from "next";

export async function generateStaticParams() {
  return listarAulasMeta().map((a) => ({ slug: a.slug }));
}

export async function generateMetadata({
  params,
}: {
  params: Promise<{ slug: string }>;
}): Promise<Metadata> {
  const { slug } = await params;
  const aula = await getAula(slug);
  return {
    title: aula ? `${aula.titulo} — Base C` : "Aula — Base C",
  };
}

export default async function AulaPage({
  params,
}: {
  params: Promise<{ slug: string }>;
}) {
  const { slug } = await params;
  const aula = await getAula(slug);
  if (!aula) notFound();

  return <AulaLayout aula={aula} />;
}
