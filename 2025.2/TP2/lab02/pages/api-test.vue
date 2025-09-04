<template>
  <div>
    <h1>API Test</h1>
    <p>{{ data.message }}</p>
  </div>
</template>

<script setup>
const { data } = await useFetch("/api/hello");
</script>
