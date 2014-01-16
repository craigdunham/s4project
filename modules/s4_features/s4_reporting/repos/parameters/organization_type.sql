--ACCESS=access s4 reporting
select distinct t.tid, t.name FROM taxonomy_term_data t LEFT JOIN taxonomy_vocabulary v ON t.vid = v.vid WHERE v.machine_name = 'organization_type' ORDER BY t.name