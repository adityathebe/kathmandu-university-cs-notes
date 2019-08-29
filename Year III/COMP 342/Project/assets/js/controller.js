// Global variables
let mass1 = 1;
let mass2 = 0.9;
let length1 = 1;
let length2 = 0.9;
let pendulum;

const form = document.querySelector('form');
const mass_field_1 = document.getElementById('form-mass-1');
const mass_field_2 = document.getElementById('form-mass-2');
const length_field_1 = document.getElementById('form-length-1');
const length_field_2 = document.getElementById('form-length-2');

form.addEventListener('submit', (event) => {
    event.preventDefault();
    if (mass_field_1.value) pendulum.m1 = Number(mass_field_1.value);
    if (mass_field_2.value) pendulum.m2 = Number(mass_field_2.value);
    if (length_field_1.value) pendulum.l1 = Number(length_field_1.value);
    if (length_field_2.value) pendulum.l1 = Number(length_field_2.value);
})

noLoop();
