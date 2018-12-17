# UE4-VRHands-Template
This is a Unreal Engine 4 template for VR Headsets with motion controllers. It features dynamic hands, touch screens, grabbable objects, and locomotion.

The template supports UE4 version 4.21

If you are using the UE4 launcher, put the template into UE4 by putting the TP_VRHands_BP folder into: 
C:\Program Files\Epic Games\UE_4.21\Templates

<a href="https://docs.unrealengine.com/en-US/Engine/Basics/Projects/CreatingTemplates" target="_blank">See Creating Templates for help setting up.</a>

When making a new map with VRHands functionality, use the VRPawn as a pawn, place a nav mesh to allow the pawn to move. For the grabbable object highlight, place a post process volume with the Highlight material in the Post Process Materials array under Rendering Features category and make sure you have the correct rendering settings in the project settings (forward shading, vertex fogging for opaque, custom depth-stencil pass set to enabled with stencil). If you want a cursor above the grabbable object then just wire up the cursor in the highlight function of the Grabbable component.

For grabbable objects, create an actor with a Grabbable component and static mesh then set the grab kind for the Grabbable component at event begin play. See the CubeBP for example.

This uses BP from this <a href="https://youtu.be/lMieSD_7nSg" target="_blank">Arm Swinger Style Movement Tutorial for Unreal 4 video</a>.

It also uses this <a href="https://youtu.be/bWXI91FdMtk" target="_blank">Ue4 Tutorial - Moving an Object along a path using a Spline Track video</a>.

For the dynamic hands, grabbable objects and highlighting is from <a href="https://forums.unrealengine.com/development-discussion/vr-ar-development/1381972-uvrf-handpresence-template-for-rift-vive-free-shooting-range-update-1-3-laser-interactions" target="_blank">UVRF project template</a>.

Also, this uses <a href="https://useiconic.com/icons/hand/" target="_blank">open iconic</a> for the template graphic.

Touch Screen interaction was figured out from this <a href="https://answers.unrealengine.com/questions/669917/vr-touch-screen-interaction.html" target="_blank">answer by AllJonasNeeds at UnrealEngine.com</a>.

The incremental move (forward, back, strafe right, strafe left, turn right, turn left) by throwing a ball a meter away onto the nav mesh was my work.

There is a bug that I couldn't fix, it happens when the player does a spline move after a teleport--what happens is any CheckLineCollision function for the spline move will hit a Model Component for unknown reasons and then you would have to just use the trace end which makes it seems pointless but it works as I couldn't spline move across the box brush table.
