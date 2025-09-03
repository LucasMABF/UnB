<template>
  <div class="counter">
    <h2>Counter</h2>
    <p class="value">{{ count }}</p>
    <div class="controls">
      <button
        :style="{ visibility: count > 0 ? 'visible' : 'hidden' }"
        @click="decrement"
      >
        --
      </button>
      <button @click="increment">++</button>
      <button @click="reset">Reset</button>
    </div>
  </div>
</template>

<script setup>
import { ref } from "vue";
const count = ref(0);

const increment = () => count.value++;
const decrement = () => count.value--;
const reset = () => (count.value = 0);
</script>

<style scoped>
.counter {
  background-color: var(--bg-light);
  display: flex;
  flex-direction: column;
  align-items: center;
  gap: 1.2rem;
  max-width: 300px;
  margin: 1.5rem auto;
  padding: 2rem;
  border-radius: 12px;
}

h2 {
  margin: 0;
}

.value {
  font-size: 2rem;
  margin: 0;
}

.controls {
  display: flex;
  gap: 1rem;
}

button {
  border-radius: 8px;
  padding: 0.6rem 1rem;
  border: 1px solid #3b4261;
  background-color: var(--bg-dark);
  color: #c0caf5;
  font-size: 1rem;
  font-family: inherit;
  transition:
    border-color 0.25s,
    box-shadow 0.25s,
    background-color 0.25s;
}

button:hover {
  border-color: var(--accent);
  background-color: #2e344f;
}

.value {
  color: var(--accent);
}
</style>
