#!/usr/bin/node

const util = require('util');
const request = util.promisify(require('request'));
const num = process.argv.slice(2);

async function checkcharacters (star) {
  const url = 'https://swapi-api.hbtn.io/api/films/' + star;
  let data = await (await request(url)).body;
  data = JSON.parse(data);
  const characters = data.characters;
  for (let y = 0; y < characters.length; y++) {
    const urlCharacter = characters[y];
    let character = await (await request(urlCharacter)).body;
    character = JSON.parse(character);
    console.log(character.name);
  }
}

checkcharacters(num[0]);
