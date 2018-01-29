const CANVAS_HEIGHT = 700;
const CANVAS_WIDTH = 700;
const GAME_IN_PROGRESS = 1;
const GAME_WON = 2;
const GAME_LOST = 3;
const MIN_DELTA = 6;
const BALLS_PER_LEVEL = 3;
const OBSTACLE_HTML = '<circle id="obstacle" class="obstacle" cx="{{posX}}" cy="{{posY}}" r="{{radius}}" stroke="red" stroke-width="3" fill="red" />'
const INITIAL_HTML = '<rect id="background"/> <rect class="tile" id="finish" x="0" y="0"/> <rect class="tile" id="start" x="650" y="650"/> <circle id="obstacle" class="obstacle" cx="50" cy="80" r="40" stroke="red" stroke-width="3" fill="red" />'
const WIN_AUDIO_FILE = 'http://www.wavsource.com/snds_2018-01-14_3453803176249356/tv/simpsons/homer/award.wav'
const LOSE_AUDIO_FILE = 'http://www.wavsource.com/snds_2018-01-14_3453803176249356/tv/simpsons/homer/doh1_y.wav'

let gameState = GAME_IN_PROGRESS;
let obstacleElements = document.getElementsByClassName('obstacle');
let startTile = document.getElementById('start');
let finishTile = document.getElementById('finish');
let timerFunction = setInterval(moveBall, 20);
let canvas = document.getElementById('canvas');
let levelTittle = document.getElementById('level-tittle')
let currentLevel = 1;
let winAudio = new Audio(WIN_AUDIO_FILE);
let loseAudio = new Audio(LOSE_AUDIO_FILE);

updateElements();


function youLose() {
  if(gameState === GAME_IN_PROGRESS) {
    endAnimation();
    loseAudio.play();
    alert("You Lose");
    gameState = GAME_LOST;
  }
}

function endAnimation() {
  clearInterval(timerFunction);
  timerFunction = null;
}

function youWon() {
  if(gameState === GAME_IN_PROGRESS) {
    endAnimation();
    currentLevel++;
    levelTittle.innerText = "Level " + currentLevel;
    winAudio.play();
    alert("You Won");
    gameState = GAME_WON;
  }
}

function restartGame() {
  if(!timerFunction && gameState != GAME_IN_PROGRESS) {
    canvas.innerHTML = INITIAL_HTML;
    for(let i = 0; i < currentLevel*BALLS_PER_LEVEL; ++i) {
      let randRadius = Math.floor(Math.random() * 20) + 20;
      let randPosX = randomPositions()[0];
      let randPosY = randomPositions()[1];
      addBall(randRadius, randPosX, randPosY);
    }
    timerFunction = setInterval(moveBall, 20);
    gameState = GAME_IN_PROGRESS;
  }
}

function updateElements() {
  obstacleElements = document.getElementsByClassName('obstacle');
  startTile = document.getElementById('start');
  finishTile = document.getElementById('finish');
  startTile.addEventListener('mouseover', restartGame);
  finish.addEventListener('mouseover', youWon);
}

let isMovingEast = true;

function moveBall() {
  for (obstacleElement of obstacleElements) {
    updateElements();
    obstacleElement.addEventListener('mouseover', youLose);
    obstacleElement.deltaX = obstacleElement.deltaX || (getRandomDelta()[0] * randomNegative());
    obstacleElement.deltaY = obstacleElement.deltaY || (getRandomDelta()[1] * randomNegative());
    let x = parseInt(obstacleElement.getAttribute('cx'));
    let y = parseInt(obstacleElement.getAttribute('cy'));
    if(y >= CANVAS_HEIGHT) obstacleElement.deltaY = getRandomDelta()[1] * -1;
    if(x >= CANVAS_WIDTH) obstacleElement.deltaX = getRandomDelta()[0] * -1;
    if(x <= 0) obstacleElement.deltaX = getRandomDelta()[0];
    if(y <= 0) obstacleElement.deltaY = getRandomDelta()[1];

    obstacleElement.setAttribute("cx", x + obstacleElement.deltaX);
    obstacleElement.setAttribute("cy", y + obstacleElement.deltaY);
  }
}

function addBall(radius, posX, posY) {
  let propToReplace = ["{{radius}}", "{{posX}}", "{{posY}}"];
  let innerHTML = OBSTACLE_HTML.replace(new RegExp(propToReplace[0], "g"), radius);
  innerHTML = innerHTML.replace(new RegExp(propToReplace[1], "g"), posX);
  innerHTML = innerHTML.replace(new RegExp(propToReplace[2], "g"), posY);
  canvas.innerHTML += innerHTML;
}

function getRandomDelta() {
  let deltaX = Math.floor(Math.random() * 6) + MIN_DELTA;
  let deltaY = Math.floor(Math.random() * 6) + MIN_DELTA;
  return [deltaX, deltaY];
}

function randomPositions() {
  let posX = Math.floor(Math.random() * CANVAS_WIDTH);
  let posY = Math.floor(Math.random() * CANVAS_HEIGHT);
  return [posX, posY];
}

function randomNegative() {
  let randomNumber = Math.floor(Math.random()*2);
  if(randomNumber === 0) return -1;
  else return 1;
}
