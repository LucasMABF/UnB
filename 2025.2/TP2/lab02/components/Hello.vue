<template>
  <div class="hello">
    <h3>Hello, {{ name }}!</h3>
  </div>
</template>

<script setup>
defineProps({
  name: String,
});
</script>

<style scoped>
.hello {
  border: 1px solid #7aa2f7;
  padding: 10px;
  margin: 10px 0;
  border-radius: 1rem;
}
</style>
