<template>
  <li @click="$emit('toggle', todo.id)">
    <div>
      <input type="checkbox" :checked="todo.done" @click.stop />
      <span :class="{ done: todo.done }">{{ todo.text }}</span>
    </div>
    <button @click.stop="$emit('remove', todo.id)">
      <svg
        xmlns="http://www.w3.org/2000/svg"
        viewBox="0 0 24 24"
        width="18"
        height="18"
        fill="none"
        stroke="currentColor"
        stroke-width="2"
        stroke-linecap="round"
        stroke-linejoin="round"
      >
        <polyline points="3 6 5 6 21 6" />
        <path d="M19 6l-1 14H6L5 6m5 0V3h4v3" />
      </svg>
    </button>
  </li>
</template>

<script setup>
const props = defineProps({ todo: Object });
</script>

<style scoped>
.done {
  text-decoration: line-through;
  color: #565f89;
}

li {
  cursor: pointer;
  display: flex;
  align-items: center;
  justify-content: space-between;
  padding: 0.6rem 1rem;
  margin-bottom: 0.6rem;
  border-radius: 8px;
  background-color: var(--bg-dark);
  border: 1px solid #3b4261;
  transition:
    background-color 0.25s,
    border-color 0.25s;
}

li:hover {
  background-color: var(--bg-light);
  border-color: var(--accent);
}

span {
  font-size: 1rem;
}

button {
  background: transparent;
  border: none;
  color: #f7768e;
  font-size: 1rem;
  padding: 0.3rem 0.6rem;
  border-radius: 6px;
  display: flex;
  align-items: center;
}

input[type="checkbox"] {
  pointer-events: none;
  accent-color: var(--accent);
  width: 1.1rem;
  height: 1.1rem;
  cursor: pointer;
  margin: 0.6rem;
}
</style>
