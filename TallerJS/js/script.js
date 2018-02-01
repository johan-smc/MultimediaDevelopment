window.onload=function(){
  console.log("Pagina Cargada!");
  var primerParrafo = document.querySelector("p");
  primerParrafo.addEventListener("click",function(){
    mostrarMsj("click sobre el parrafo");
  });
  console.log(primerParrafo);
  primerParrafo.addEventListener("mouseover", function(){
    cambiarColor(this, getRandomColor());
  });

  primerParrafo.addEventListener("mouseout",function(){
    cambiarColor(this, getRandomColor());
  });

  let hexArray = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"];
  function getRandomColor() {
    let red = getRandHex() + getRandHex();
    let green = getRandHex() + getRandHex();
    let blue = getRandHex() + getRandHex();
    let color = "#" + red + green + blue;
    return color;
  }

  function getRandHex() {
    return hexArray[Math.floor((Math.random()*16))];
  }

};


function cambiarColor(elemento, color) {
  elemento.style.color=color;
}

var mostrarMsj = function(texto){
  alert(texto);
  prompt("Como va todo?");
};
