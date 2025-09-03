<template>
  <div>
    <h1>About</h1>
    <p>
      This is the About page. Click
      <a href="#" @click="redirectHome()">here</a> to go back
    </p>
  </div>
</template>

<script setup>
import { useRouter } from "vue-router";
const router = useRouter();

const redirectHome = () => {
  router.push("/");
};
</script>
