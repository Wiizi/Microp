w(1,:) = [-20.74000/1000,-105.469002/1000,1004.731018/1000,1];
y(1,:) = [0,0,1];
w(2,:) = [-44.957001/1000,-12.505000/1000,-980.208984/1000,1];
y(2,:) = [0,0,-1];
w(3,:) = [22.57000/1000,1042.001953/1000,53.68000/1000,1];
y(3,:) = [0,1,0];
w(4,:) = [64.903999/1000,-1031.754028/1000,11.102000/1000,1];
y(4,:) = [0,-1,0];
w(5,:) = [1008.085999/1000,14.579000/1000,18.849000/1000,1];
y(5,:) = [1,0,0];
w(6,:) = [-996.974025/1000,-25.986000/1000,17.445999/1000,1];
y(6,:) = [-1,0,0];
wt = w.';
cc = inv(wt*w);
x=inv(wt*w)*wt*y;