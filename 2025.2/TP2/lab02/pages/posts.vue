<template>
  <h1>Posts</h1>
  <div v-if="pending">Loading...</div>
  <div v-else class="posts-container">
    <PostCard v-for="post in data" :key="post.id" :post="post" />
  </div>
  <div v-if="error">An error occured when fetching data.</div>
</template>

<script setup>
const { data, pending, error } = await useFetch("/api/posts", { lazy: true });
</script>

<style scoped>
.posts-container {
  display: flex;
  flex-wrap: wrap;
  align-items: stretch;
  gap: 1rem;
}
</style>
