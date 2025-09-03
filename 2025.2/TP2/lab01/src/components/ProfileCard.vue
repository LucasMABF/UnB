<template>
  <div class="card">
    <img v-if="avatar" :src="avatar" alt="avatar" class="avatar" />
    <h3>{{ name }}</h3>
    <p v-if="age">Age: {{ age }}</p>
    <slot name="extra"></slot>
  </div>
</template>

<script setup>
const props = defineProps({
  name: { type: String, required: true },
  age: { type: Number, default: null },
  avatar: { type: String, default: "" },
});
</script>

<style scoped>
.card {
  background-color: var(--bg-light);
  border: 1px solid var(--accent);
  padding: 12px;
  border-radius: 8px;
  width: 220px;
  text-align: center;
}

.avatar {
  width: 80px;
  height: 80px;
  border-radius: 50%;
  object-fit: cover;
  margin-top: 8px;
}

h3 {
  margin: 10px;
}
</style>
