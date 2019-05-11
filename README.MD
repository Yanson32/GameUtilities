<h1>GameUtilities</h1>

<p>
	The GameUtilities library provides a basic 2d game framework.
</p>

<h2>Features</h2>
<ul>
	<li>Basic Game Engin</li>
	<li>Event System</li>
	<li>Particle System</li>
</ul>

<h2>Dependencies</h2>
<ul>
	<li>SFML</li>
	<li>Math</li>
	<li>Box2D</li>
</ul>

<h2>How to compile</h2>

<p>
	To build Multitheaded applications MULTITHREAD should be defined
</p>

<p>
	To build examples just set the cmake cache variable GU_BUILD_EXAMPLES to true. Remember that building the examples will add some 	additional dependancies to the build.
</p>

<h2>To Do List</h2>
<ul>
	<li>Change Events newLine default parameter from 0 to -1</li>
	<li>Add Job Queue (thread pool) to the library</li>
</ul>
