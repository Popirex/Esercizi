let r = 200;
let punti_totali = 0;
let punti_cerchio = 0;
let pi = 0;

function setup() {
  createCanvas(400, 400);
  noFill();
  strokeWeight(4);
  ellipse(width/2,height/2, r*2, r*2);
  rect(0,0, r*2);
  
}

function draw() {
  frameRate(30);
  //background(220);
  translate(width/2, height/2);
  for(let i = 0; i < 10000; i++ ){
    punti_totali++;
    let x = random(-r , r);
    let y = random(-r, r);
    let d = dist(0 , 0 , x, y);
    if( d <= r){
      stroke('#34dbeb');
      punti_cerchio++;
    }
    else{
      stroke('#810d9e');
    }
    point(x, y);
    pie = 4 * (punti_cerchio / punti_totali);
  }
  console.log(pie);
}