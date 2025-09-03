<template>
  <div class="todo">
    <h2>Todo List</h2>

    <form @submit.prevent="addTodo">
      <input v-model="new_todo" placeholder="New Task..." />
      <button type="submit">Add</button>
      <select v-model="todo_filter">
        <option>All</option>
        <option>Pending</option>
        <option>Done</option>
      </select>
      <select v-model="order">
        <option>Status</option>
        <option>Newest</option>
        <option>Oldest</option>
      </select>
    </form>

    <ul>
      <TodoItem
        v-for="todo in filtered_todos"
        :key="todo.id"
        :todo="todo"
        @toggle="updateTodo"
        @remove="removeTodo"
      />
    </ul>

    <p v-if="todos.length === 0">No tasks</p>
  </div>
</template>

<script setup>
import { ref, watch, onMounted, computed } from "vue";
import TodoItem from "./TodoItem.vue";

const todo_filter = ref("All");
const order = ref("Status");
const new_todo = ref("");
const todos = ref([]);

onMounted(() => {
  const raw = localStorage.getItem("todos");
  if (raw) {
    todos.value = JSON.parse(raw);
  }
});

const addTodo = () => {
  if (!new_todo.value.trim()) return;
  const item = {
    id: Date.now(),
    text: new_todo.value.trim(),
    done: false,
  };
  todos.value.unshift(item);
  new_todo.value = "";
};

const updateTodo = (id) => {
  const idx = todos.value.findIndex((t) => t.id === id);
  if (idx !== -1) {
    todos.value[idx].done = !todos.value[idx].done;
  }
};

const removeTodo = (id) => {
  todos.value = todos.value.filter((t) => t.id !== id);
};

const filtered_todos = computed(() => {
  let list;
  if (todo_filter.value === "All") {
    list = todos.value;
  } else if (todo_filter.value === "Done") {
    list = todos.value.filter((t) => t.done);
  } else {
    list = todos.value.filter((t) => !t.done);
  }

  if (order.value === "Newest") {
    list.sort((a, b) => b.id - a.id);
  } else if (order.value === "Oldest") {
    list.sort((a, b) => a.id - b.id);
  } else {
    list.sort((a, b) => {
      if ((a.done && !b.done) || (!a.done && b.done)) {
        return a.done - b.done;
      }
      return b.id - a.id;
    });
  }

  return list;
});

watch(
  todos,
  (nw) => {
    localStorage.setItem("todos", JSON.stringify(nw));
  },
  { deep: true },
);
</script>

<style scoped>
form {
  display: flex;
  gap: 0.2rem;
  justify-content: center;
  margin-bottom: 1.5rem;
}

h2 {
  margin-bottom: 1.5rem;
}

form > * {
  margin: 10px;
}

input,
select,
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

input:focus,
select:focus {
  outline: none;
  border-color: var(--accent);
  box-shadow: 0 0 6px rgba(122, 162, 247, 0.6);
}

button:hover {
  border-color: var(--accent);
  background-color: #2e344f;
}

.todo {
  max-width: 600px;
  margin: 2rem auto;
  padding: 2rem;
  background-color: var(--bg-light);
  border-radius: 12px;
  box-shadow: 0 4px 20px rgba(0, 0, 0, 0.3);
}

.done {
  text-decoration: line-through;
  color: #565f89;
}

ul {
  list-style: none;
  padding: 0;
  margin: 0;
}

li {
  display: flex;
  align-items: center;
  justify-content: space-between;
  padding: 8px 0;
}
</style>
