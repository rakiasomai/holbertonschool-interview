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
    let letter = await (await request(urlCharacter)).body;
    letter = JSON.parse(letter);
    console.log(letter.name);
  }
}

checkcharacters(num[0]);
