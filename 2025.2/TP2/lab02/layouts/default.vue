<template>
  <div class="main-container">
    <header>
      <h2>My Nuxt site</h2>
      <nav>
        <NuxtLink to="/">Home</NuxtLink>
        <NuxtLink to="/posts">Posts</NuxtLink>
        <NuxtLink to="/about">About</NuxtLink>
        <NuxtLink to="/contact">Contact</NuxtLink>
        <NuxtLink to="/api-test">Hello API</NuxtLink>
      </nav>
    </header>

    <main>
      <slot />
    </main>
    <footer>
      <p>&copy; 2025 - Made with Nuxt</p>
    </footer>
  </div>
</template>

<style>
body {
  margin: 0;
  padding: 0;
  background-color: #1a1b26;
  color: #c0caf5;
  font-family: Arial;
}

a {
  text-decoration: none;
  color: #7aa2f7;
  transition:
    color 0.25s,
    text-shadow 0.25s;
}

a:hover {
  text-shadow: 0 0 4px rgba(122, 162, 247, 0.7);
}
</style>

<style scoped>
.main-container {
  display: flex;
  flex-direction: column;
  height: 100vh;
}

h2 {
  margin: 0.1rem 0 0.6rem 0;
  color: #7aa2f7;
}

header {
  background-color: #16161e;
  color: #c0caf5;
  padding: 12px;
}

nav {
  display: flex;
  gap: 1.3rem;
  justify-content: left;
}

main {
  flex-grow: 1;
  padding: 20px;
}

footer {
  text-align: center;
  padding: 12px;
  margin-top: 20px;
  background-color: #16161e;
  color: #9ece6a;
}
</style>
