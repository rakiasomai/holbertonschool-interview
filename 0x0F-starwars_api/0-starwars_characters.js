#!/usr/bin/node
const util = require('util');
const request = util.promisify(require('request'));
const args = process.argv[2];

async function checkcaracters (star) {
  const url = 'https://swapi-api.hbtn.io/api/films/' + star ;
  let data = await (await request(url)).body;
  data = JSON.parse(data);
  const check = data.check;
  for (let x = 0; x < check.length; x++) {
    const urlCheck = check[x];
    let check = await (await request(urlCheck)).body;
    check = JSON.parse(check);
    console.log(check.name);
  }
}

checkcaracters(args[0]);
