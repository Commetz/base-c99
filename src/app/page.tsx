import { Hero } from "@/components/Hero";
import { Features } from "@/components/Features";
import { Estatisticas } from "@/components/Estatisticas";
import { CtaFinal } from "@/components/CtaFinal";

export default function Home() {
  return (
    <>
      <Hero />
      <Features />
      <Estatisticas />
      <CtaFinal />
    </>
  );
}
