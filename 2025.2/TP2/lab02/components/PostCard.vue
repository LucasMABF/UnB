<template>
  <div class="card">
    <h4>{{ post.title }}</h4>
    <p>{{ post.content }}</p>
    <span>{{ post.author }}</span>
  </div>
</template>

<script setup>
defineProps({
  post: {
    title: String,
    content: String,
    author: String,
  },
});
</script>

<style scoped>
.card {
  background-color: #24283b;
  border: 1px solid #7aa2f7;
  padding: 10px;
  margin: 10px 0;
  border-radius: 1rem;
  width: 350px;
  padding: 1rem;
}

p {
  white-space: no-wrap;
  overflow: hidden;
  text-overflow: ellipsis;
}

h4 {
  color: #7aa2f7;
}

span {
  color: #565f89;
}

</style>
