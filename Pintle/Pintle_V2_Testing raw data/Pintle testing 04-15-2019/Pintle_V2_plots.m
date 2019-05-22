%{

Plots for comparing pintle V2 hydro test with hand calcs and CFD model

%}

pintle_massflow_actual = [0.4232, 0.4150, 0.4037, 0.3822, 0.3854, 0.3910, 0.3387, 0.3494, 0.3500]   ;
pintle_massflow_sims = [0.35, 0.4, 0.4082, 0.45, 0.5]                                               ;
pintle_pressure_actual = [400.241,406.653,412.789,343.566,338.050,341.635,268.068,264.897,264.621]  ;
pintle_pressure_cfd = [360.566, 452.661,499.681,570.987,703.053]                                    ;

annulus_massflow_actual = [0.4560,0.4844,0.4844,0.4831,0.4730,0.4447,0.3898,0.4245,0.4074]          ;
annulus_massflow_sims = [0.4,0.45,0.5,0.5262,0.55]                                                  ;
annulus_pressure_actual = [428.234,431.612,443.816,455.054,458.226,462.845,356.666,360.872,355.425] ;
annulus_pressure_cfd = [273.47,335.49,402.909,445.954,482.202]                                      ;


% pintle theoretical graph
pintle_kl   = 2.518       ;
pintle_k_actual   = 2.13       ;
pintle_area = 0.00002153  ;
density     = 999.7       ;

pintle_x = linspace(.3, .5, 40); 
pintle_pressure = [] ;
pintle_pressure_est = []

for i=1:length(pintle_x)
    pintle_pressure(i)= ((pintle_kl * density * .5 * pintle_x(i)/(density*pintle_area))^2)/1000000;
    pintle_pressure_est(i)= ((pintle_k_actual * density * .5 * pintle_x(i)/(density*pintle_area))^2)/1000000;
end


pintle_target_pressure = [361.9748, 482.633, 603.291]
pintle_target_massflow = [0.4082, 0.4082, 0.4082]




% annulus theoretical graph
annulus_kl   = 1.49       ;
annulus_k_actual = 1.92
annulus_area = 0.00002155  ;
density     = 999.7       ;

annulus_x = linspace(.35, .6, 40); 
annulus_pressure = [] ;
annulus_pressure_est = [] ;

for i=1:length(annulus_x)
    annulus_pressure(i)= ((annulus_kl * density * .5 * annulus_x(i)/(density*annulus_area))^2)/1000000; 
    annulus_pressure_est(i)= ((annulus_k_actual * density * .5 * annulus_x(i)/(density*annulus_area))^2)/1000000;
end


annulus_target_pressure = [361.9748, 482.633, 603.291]
annulus_target_massflow = [0.5262, 0.5262, 0.5262]



% pintle plot

loglog(pintle_pressure_actual, pintle_massflow_actual, 'rx')
hold on
loglog(pintle_pressure_cfd, pintle_massflow_sims, 'b^')
hold on
%loglog(pintle_pressure,pintle_x, 'k--')
%hold on
loglog(pintle_target_pressure, pintle_target_massflow, 'sm:')
hold on
loglog(pintle_pressure_est,pintle_x, 'r--')
title('Pintle: Mass Flow Rate vs. Pressure')
xlabel('Pressure (kPa)');   ylabel('Mass Flow Rate (kg/s)');
legend('Measured', 'CFD', 'Target','Location','northwest');

figure


% annuslus plot

loglog(annulus_pressure_actual, annulus_massflow_actual, 'rx')
hold on
loglog(annulus_pressure_cfd, annulus_massflow_sims, 'b^')
hold on
%loglog(annulus_pressure,annulus_x, 'k--')
%hold on
loglog(annulus_target_pressure, annulus_target_massflow, 'sm:')
loglog(annulus_pressure_est,annulus_x, 'r--')
hold on
title('Annulus: Mass Flow Rate vs. Pressure')
xlabel('Pressure (kPa)');   ylabel('Mass Flow Rate (kg/s)');
legend('Measured', 'CFD', 'Target','Location','northwest');



