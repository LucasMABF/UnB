export default defineEventHandler(async () => {
  await new Promise((r) => setTimeout(r, 3000));
  return [
    {
      title: "My first Nuxt site",
      content:
        "Building my very first Nuxt application and learning the basics of pages, layouts, and components",
      author: "Alice",
    },
    {
      title: "Exploring Nuxt 3",
      content: "Nuxt 3 introduces new features",
      author: "Bob",
    },
    {
      title: "Understanding Vue 3",
      content: "Vue 3 has Composition API",
      author: "Charlie",
    },
    {
      title: "Global State in Nuxt",
      content: "Using useState and composables",
      author: "Eve",
    },
    {
      title: "Async Data Fetching",
      content: "Fetching data with useFetch",
      author: "Frank",
    },
    {
      title: "Nuxt Layouts",
      content: "Organizing pages and layouts",
      author: "Grace",
    },
    {
      title: "SEO Tips for Nuxt",
      content: "Meta tags and SSR considerations",
      author: "Hank",
    },
    {
      title: "Deploying Nuxt Apps",
      content: "Vercel, Netlify, and static hosting",
      author: "Ivy",
    },
    {
      title: "Nuxt Plugins",
      content: "Extending functionality with plugins",
      author: "Jack",
    },
  ];
});
