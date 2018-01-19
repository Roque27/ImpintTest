BEGIN 
INSERT INTO control_procesos (cpr_numero,cpr_tipo_proceso,usr_numero_incorpora,prc_codigo,est_codigo,cpr_fecha_inicio) VALUES(1255449, 'IN', 1255, 'IN', 'P', TO_DATE('10/10/2017', 'MM/DD/YYYY')); UPDATE control_procesos SET est_codigo = 'I' WHERE cpr_numero = 1255449; exception when others then ROLLBACK; dbms_output.put_line('ERROR en Exception'); end;
