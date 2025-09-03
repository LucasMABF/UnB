<template>
  <div>
    <input v-model="msg" />
    <p>
      Label: <strong>{{ msg }}</strong>
    </p>
  </div>
</template>

<script setup>
import { ref } from "vue";
const msg = ref("message");
</script>

<style scoped>
div {
  display: flex;
  flex-direction: column;
  gap: 1rem;
  max-width: 400px;
  margin: 0 auto;
  padding: 2rem;
  background-color: var(--bg-light);
  border-radius: 12px;
  box-shadow: 0 4px 20px rgba(0, 0, 0, 0.3);
}

label {
  display: flex;
  flex-direction: column;
  gap: 0.5rem;
  font-weight: 500;
}

input {
  padding: 0.6rem 0.8rem;
  border-radius: 8px;
  border: 1px solid #3b4261;
  background-color: var(--bg-dark);
  color: #c0caf5;
  font-size: 1rem;
  transition:
    border-color 0.25s,
    box-shadow 0.25s;
}

input:focus {
  outline: none;
  border-color: var(--accent);
  box-shadow: 0 0 6px rgba(122, 162, 247, 0.6);
}

p {
  margin: 0;
  font-size: 1rem;
  color: #9aa5ce;
}

p strong {
  color: var(--accent);
}
</style>
