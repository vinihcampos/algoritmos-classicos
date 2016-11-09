var l, r, mid, found;
var numbers = new Array(10);

function reset(){
	l = 0; 
	r = 9; 
	mid = Math.floor((l + r) / 2);; 
	found = false;
}

function generateNumbers(){
	for(i = 0; i < 10; i++){
		numbers[i] = Math.floor(Math.random() * 101);
	}
	numbers.sort(function(a, b){return a - b});
	for(i = 0; i < numbers.length; i++){
		document.getElementById("ani"+(i+1)).innerHTML = numbers[i].toString();
	}
	reset();
	resetColor();
	coloring();
}


function bb(){
	var x = document.getElementById('numberUser').value;
	if(l < r && !found){
		var v_mid = $('#ani'+ (mid + 1)).text();
		if(parseInt(v_mid) == x){
			found = true;
		}else if(parseInt(v_mid) > x){
			r = mid - 1;
			mid = Math.floor((l + r) / 2);
		}else{
			l = mid + 1;
			mid = Math.floor((l + r) / 2);
		}
	}
	coloring();
}
function resetColor(){
	for(i = 0; i < numbers.length; i++){
		$('#ani'+ (i + 1)).css("background", "none");
	}
}
function coloring(){
	resetColor();
	if(found)
		$('#ani'+ (mid + 1)).css("background", "red");
	else if(!found && l < r){		
		$('#ani'+ (r + 1)).css("background", "green");
		$('#ani'+ (l + 1)).css("background", "blue");	
		$('#ani'+ (mid + 1)).css("background", "red");
	}else{
		for(i = 0; i < numbers.length; i++){
			$('#ani'+ (i + 1)).css("background", "red");
		}
	}
}
