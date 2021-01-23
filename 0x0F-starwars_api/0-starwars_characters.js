#!/usr/bin/node
const request = require('request');

async function checkcaracters () {
  const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];
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
