<template>
  <h2>Global counter</h2>
  <div class="counter">
    <span>{{ count }}</span>
    <button @click="count++">++</button>
  </div>
</template>

<script setup>
const count = useState("count", () => 0);
</script>

<style scoped>
.counter {
  display: flex;
  align-items: center;
  border: 1px solid #7aa2f7;
  padding: 10px;
  margin: 10px 0;
  border-radius: 1rem;
}

span {
  min-width: 40px;
  padding: 4px 8px;
  background-color: #1a1b26;
  color: #7aa2f7;
  border: 1px solid #7aa2f7;
  border-radius: 4px;
  font-weight: bold;
  margin: 1rem;
  font-size: 50px;
  text-align: center;
}

button {
  margin-left: 8px;
  padding: 6px 12px;
  background-color: #7aa2f7;
  color: #1a1b26;
  border: none;
  border-radius: 4px;
  cursor: pointer;
  font-weight: bold;
  min-height: 35px;
}

button:hover {
  background-color: #5c7cfa;
  color: #1a1b26;
}
</style>
