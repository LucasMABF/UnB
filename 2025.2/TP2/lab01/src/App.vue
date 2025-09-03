<template>
  <nav>
    <router-link to="/">Home</router-link>
    <router-link to="/about">About</router-link>
  </nav>

  <main>
    <router-view></router-view>
  </main>
</template>

<style scoped>
main {
  display: flex;
  place-items: center;
  min-width: 320px;
  text-align: center;
  flex-direction: column;
}

nav {
  margin: 1rem;
  display: flex;
  gap: 2rem;
  padding: 1rem 2rem;
  background-color: var(--bg-light);
  box-shadow: 0 2px 10px rgba(0, 0, 0, 0.3);
  border-radius: 10px;
  justify-content: left;
}

nav a {
  text-decoration: none;
  transition:
    color 0.25s,
    text-shadow 0.25s;
}

nav a:hover {
  text-shadow: 0 0 4px rgba(122, 162, 247, 0.7);
}
</style>
