<script setup>
import HelloWorld from "../components/HelloWorld.vue";
import Label from "../components/Label.vue";
import Counter from "../components/Counter.vue";
import TodoList from "../components/TodoList.vue";
import ProfileCard from "../components/ProfileCard.vue";
</script>

<template>
  <HelloWorld />
  <Label />
  <Counter />
  <TodoList />
  <div class="cards-container">
    <ProfileCard name="João" :age="28" avatar="https://i.pravatar.cc/150?u=14">
      <template #extra>
        <p>CS student</p>
      </template>
    </ProfileCard>
    <ProfileCard name="Joana" :age="23" avatar="https://i.pravatar.cc/150?u=1">
      <template #extra>
        <p>CS student</p>
      </template>
    </ProfileCard>
  </div>
</template>

<style scoped>
.cards-container {
  display: flex;
  gap: 16px;
  flex-wrap: wrap;
}
</style>
