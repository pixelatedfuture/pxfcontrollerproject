# pxfcontrollerproject
A hardware controller project for LED strips


 <html>
  <head></head>
	<body>
		<!-- NOTE: ?api=1 and player_id at the end of the URL -->
			<iframe id="player" width="" height="" src="https://vimeo.com/504142414" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>

			<script src="http://a.vimeocdn.com/js/froogaloop2.min.js"></script>

			<script>	
				var player = $f(document.getElementById('player'));
				player.addEvent('ready', function() { 
				player.api('play');
				});
			</script>
	</body>
</html>






A simple roadmap for a DIY hardware controller for use with LED applications. - See PDF for assembly guide & Full Parts list w/ Links. 

Parts Required: 

5v LED Strip 16ft /
Power Supply / 
Enclosure / 
Arduino Nano Clone / 
PCB / 
PCB Standoffs / 
Resistors / 
Capacitors / 
Toggle Switch / 
Knobs / 
Potentiometer / 
4 Pin Waterproof Connector / 
LED Power Wire / 
WireKit / 
Arcade Buttons / 
Barrel Connector / 
Rubber Grommet Kit / 


Arduino Sketch Will require configuration based on your pin configuration. 

Current Sketch Includes: 
8 Pre Programed Modes//
Hue/Saturation/Brightness or Effect Adjustment Knobs //
2 LED Outputs - Can run 1-16ft strip or 2-8ft strips 



Most importantly: This guide/project was created from open source code / tutorial based learning during quarrantine. 
PCB Design / Printing coming in future verisons and will be open sourced as well. 

--THANK YOU to the open source // Arduino // FastLED community for the feedback/code suggestions/and inspiration. 
