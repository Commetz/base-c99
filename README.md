# Base C

Material de extensão universitária (UNIOESTE) para aprender C99 do zero — aulas guiadas e exercícios resolvidos do Beecrowd, organizados por categoria.

Reescrito em **Next.js + TypeScript + Tailwind CSS**, substituindo a versão anterior em HTML/CSS/JS estático.

## Por que mudou

A versão anterior tinha:
- HTML duplicado em 7 arquivos diferentes (navbar, head, etc. copiados e colados)
- Um `index.html` com 1100+ linhas misturando conteúdo de 6 aulas + JS embutido
- Lista de arquivos `.c` **hardcoded** dentro do JS de cada página de categoria — toda vez que alguém resolvia um exercício novo, precisava editar manualmente um array no HTML
- Um bug visual: o botão de aba ativo tinha o texto da mesma cor do fundo (invisível)

Agora:
- **Zero duplicação** — navbar, footer e layout são componentes únicos
- **Conteúdo como dados** — aulas são arquivos `.md`, exercícios são lidos automaticamente da pasta `content/exercicios/<categoria>/`
- **Adicionar um exercício novo = só adicionar o arquivo `.c` na pasta certa.** Nenhum código precisa ser tocado.

## Como rodar localmente

Pré-requisitos: [Node.js](https://nodejs.org) 20+.

```bash
npm install
npm run dev
```

Abra http://localhost:3000

## Como adicionar conteúdo

## Estrutura do site

- **Home (`/`)** — landing de apresentação: proposta de valor, o que o site oferece, números reais (aulas/exercícios/categorias) e atalhos para começar. Não mostra mais conteúdo de aula direto.
- **Aulas (`/aulas/[slug]`)** — cada aula escrita, incluindo a Introdução (agora em `/aulas/intro`), com espaço para vídeo-aula no topo.
- **Exercícios (`/exercicios/[categoria]`)** — lista de exercícios em cards (com dificuldade, tags, indicador de vídeo). Ao selecionar um exercício, abre em duas colunas: **vídeo-aula + enunciado** à esquerda, **código** à direita — pensado para vocês gravarem uma explicação por exercício, focada na lógica da solução.

## Como adicionar conteúdo

### Adicionar um exercício resolvido

Basta colocar o arquivo `.c` na pasta da categoria certa, dentro de `content/exercicios/`:

```
content/exercicios/
├── iniciante/
│   ├── 1000.c
│   ├── 1001.c
│   └── ...
├── geral/
├── adhoc/
├── strings/
├── matematica/
└── estruturas/
```

O nome do arquivo deve ser `<numero-do-beecrowd>.c` (ex: `1000.c`). O site detecta o arquivo automaticamente — não precisa editar nenhum código.

**O título do exercício é extraído automaticamente** da primeira linha do arquivo, então mantenham o padrão:

```c
// 1002 Beecrowd - Área Do Círculo
// Por SeuNome
```

A dificuldade (Fácil/Médio/Difícil) já vem padrão pela categoria (`iniciante`/`geral` = Fácil, `strings`/`matematica` = Médio, `adhoc`/`estruturas` = Difícil). Para enriquecer um exercício com **tags, descrição do enunciado, vídeo-aula ou dificuldade diferente do padrão**, edite `content/exercicios-meta.json`:

```json
"iniciante/1002": {
  "tags": ["ponto flutuante", "fórmulas"],
  "descricao": "Leia o raio de um círculo e calcule sua área.",
  "dificuldade": "facil",
  "video": "https://www.youtube.com/watch?v=XXXXXXXXXXX"
}
```

A chave é `categoria/numero`. Todos os campos são opcionais — um exercício sem entrada nesse arquivo continua funcionando normalmente, só aparece com o aviso "vídeo-aula ainda não gravada" e sem enunciado resumido (o aluno é direcionado ao Beecrowd).

> A ideia é gravarem um vídeo curto por exercício, explicando a lógica da solução (não só lendo o código) — o `video` é por onde isso entra.

### Criar uma nova categoria

Se um dia quiserem uma 7ª categoria, edite `src/lib/categorias.ts` e adicione um novo objeto ao array `CATEGORIAS`. A rota e a página são geradas automaticamente.

### Editar ou adicionar uma aula

As aulas estão em `content/aulas/`, como arquivos Markdown com um cabeçalho (frontmatter) no topo:

```markdown
---
ordem: 7
slug: aula-7
titulo: "Nome da Aula"
endereco: "0x07"
video: "https://www.youtube.com/watch?v=XXXXXXXXXXX"
---

Conteúdo normal em Markdown aqui, incluindo blocos de código:

```c
#include <stdio.h>
```
```

O campo `video` é opcional — sem ele, a página mostra um aviso de "vídeo-aula ainda não gravada". Quando gravarem, basta colar o link do YouTube nesse campo.

Para criar uma aula nova, crie um arquivo `content/aulas/07-aula-7.md` seguindo esse padrão. Ela aparece automaticamente na navegação.

### Editar a home

A home (`src/app/page.tsx`) é montada a partir de 4 componentes, cada um isolado:
- `src/components/Hero.tsx` — primeira tela, com a animação de "digitação" do código
- `src/components/Features.tsx` — cards de "o que você encontra aqui" (edite o array `FEATURES`)
- `src/components/Estatisticas.tsx` — números reais, calculados automaticamente a partir do conteúdo (não precisa atualizar manualmente)
- `src/components/CtaFinal.tsx` — chamada final para ação

## Estrutura do projeto

```
src/
├── app/                    # Rotas (Next.js App Router)
│   ├── page.tsx            # Home (mostra a Introdução)
│   ├── aulas/[slug]/       # Página de cada aula
│   ├── exercicios/[categoria]/  # Página de cada categoria
│   └── api/exercicios/...  # API que serve o código com syntax highlight
├── components/             # Componentes React reutilizáveis
└── lib/                    # Lógica de leitura de dados (aulas, exercícios)

content/
├── aulas/                  # Conteúdo das aulas em Markdown
└── exercicios/             # Soluções .c organizadas por categoria
```

## Stack

- [Next.js](https://nextjs.org) (App Router)
- [Tailwind CSS](https://tailwindcss.com)
- [Shiki](https://shiki.style) — syntax highlighting do código C
- [Lucide](https://lucide.dev) — ícones

**Sobre as fontes:** o projeto usa fontes de sistema (já instaladas em qualquer Windows/Mac/Linux) em vez de baixar fontes do Google. Isso evita erros de build em redes com firewall/proxy restritivo (comum em redes de faculdade). Se quiser usar fontes do Google novamente, edite `src/app/layout.tsx` e `src/app/globals.css` reintroduzindo `next/font/google` — mas só funciona em redes sem bloqueio para `fonts.gstatic.com`.

## Deploy

Recomendado: [Vercel](https://vercel.com) (gratuito para projetos como esse, deploy automático a cada push).
