import axios from 'axios';

async function getResults(query) {
    const proxy = 'https://cors-anywhere.herokuapp.com/';
    const key = '462b1cc8d4f2730081462fbc65136320';
    try {
        const res = await axios(`${proxy}http://food2fork.com/api/search?key=${key}&q=${query}`);
        const recipes = res.data.recipes;
        console.log(recipes);
    } catch (error) {
        alert(error);
    }
}
getResults('pizza');