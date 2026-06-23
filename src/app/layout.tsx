import type { Metadata } from "next";
import "./globals.css";
import { Navbar } from "@/components/Navbar";
import { Footer } from "@/components/Footer";

export const metadata: Metadata = {
  title: "Base C — Fundamentos de C99 para calouros",
  description:
    "Material de extensão universitária para aprender C99 do zero: aulas guiadas e exercícios resolvidos do Beecrowd, organizados por categoria.",
};

export default function RootLayout({
  children,
}: Readonly<{
  children: React.ReactNode;
}>) {
  return (
    <html lang="pt-BR" className="h-full">
      <body className="min-h-full flex flex-col bg-bg text-fg font-body antialiased selection:bg-accent/30 selection:text-fg">
        <Navbar />
        <main className="flex-1">{children}</main>
        <Footer />
      </body>
    </html>
  );
}
