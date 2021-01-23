#!/usr/bin/node
const util = require('util');
const request = util.promisify(require('request'));
const args = process.argv.slice(2);

async function starwarsCharacters (film) {
  const url = 'https://swapi-api.hbtn.io/api/films/' + film;
  let data = await (await request(url)).body;
  data = JSON.parse(data);
  const characters = data.characters;
  for (let index = 0; index < characters.length; index++) {
    const urlCharacter = characters[index];
    let character = await (await request(urlCharacter)).body;
    character = JSON.parse(character);
    console.log(character.name);
  }
}

starwarsCharacters(args[0]);
