<template>
  <div>
    <h1>Contact</h1>
    <p>The global counter is at: {{ count }}</p>
    <NuxtLink to="/">Go back</NuxtLink>
  </div>
</template>

<script setup>
const count = useState("count");
</script>
