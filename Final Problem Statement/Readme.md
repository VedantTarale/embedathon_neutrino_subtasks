# Embedathon Team Neutrino
Repo for Embedathon Software Subtask - Team Neutrino <br>
Team members: Vedant and Vignesh
<hr>
Drive Link:
https://drive.google.com/drive/folders/1pXqXEpNgW2x99OAyuWG-MbaCW9YfbZs-?usp=sharing
<hr>
<h3>Components Used:</h3>
<ul>
<li>Node MCU</li>
<li>MPU 6050</li>
<li>MicroUSB cable</li>
<li>PowerBank to use Node MCU without pluggin into PC (NO SERIAL COMMUNICATION --> used in MileStones 2,4,5 and Minecraft)</li>
<li>Jumper Cables</li>
<li>Pullup Switch --> for Milestones 4,5 and Minecraft </li>
<li>Node MCU in-built pullup Switch --> for Milestones 4,5 and Minecraft</li>
</ul>
<hr>
MileStone1:
<br>
	<ul><li>
	The code fetches raw accelerometer data from MPU6050 using I2C communication. Coded using Wire.h library in embededed C	
	</li></ul>
<hr>
MileStone2:
<br>
	<ul>
	<li>Implemented Wifi communication between nodeMCU and PC for data transfer.</li>
	<li>A websocket connection was established.</li>
	<li>On the PC side of things, a code written in Python handles the incoming data and displays it on a webpage.</li>
	</ul>
<hr>
MileStone3:
<br>
	<ul>
	<li>Data from MPU6050 was cliberated by compensating for the average error taken from 100readings.</li>
	<li>The caliberated data was used to calculate Angle from the X and Y axes.</li>
	<li>![Screenshot 2023-02-11 143049](https://user-images.githubusercontent.com/95867745/218252489-f8447de7-dd86-495b-92cd-dfaeb7c2fdcd.jpg)</li>
	</ul>
<hr>
MileStone4:
<br>
	<ul>
	<li>Data from nodeMCU was sent to PC by using HTTP requests.</li>
	<li>On the PC side a code written in Python made a HTTP GET request to the nodeMCU server's root path ('/')</li>
	<li>On receiving the request nodeMCU calculates angles from the accelerometer in MPU6050 sends this data along with the state of the INPUT_PULLUP button input as the response to the request with a status code of 200</li>
	<li>The Python code breaks the received response into useful readings corresponding to Angle form X-axix, Angle form Y-axis and the button state</li>
	<li>Using if-else conditions and the <b>Keyboard</b> and <b>Mouse</b> liblaries the reading were used to trigger W , A, S, D keys and the mouse button.</li>
	</ul>
<hr>
MileStone5:
<br>
	<ul>
	<li>The code improves on the MileStone 4 code by introducing an additional switch button to be used as Right Mouse Button.</li>
	<li>By adding small delays in the code, No More Snow game was played.</li>
	</ul>
<hr>
Minecraft:
<br>
	<ul>
	<li>The code is a modified varsion of the MileStone 5.</li>
	<li>Rather than having the accelerometer values to trigger WASD keys, the values were used to trigger mouse drag events.</li>
	<li>Minecraft was played using the modified code.</li>
	</ul>
<hr>
