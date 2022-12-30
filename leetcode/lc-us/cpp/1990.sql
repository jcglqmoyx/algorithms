select 'Android' as platform, 'Reading' as experiment_name, ifnull(count(*), 0) as num_experiments
from Experiments
where platform = 'Android'
  and experiment_name = 'Reading'
union all
select 'Android' as platform, 'Sports' as experiment_name, ifnull(count(*), 0) as num_experiments
from Experiments
where platform = 'Android'
  and experiment_name = 'Sports'
union all
select 'Android' as platform, 'Programming' as experiment_name, ifnull(count(*), 0) as num_experiments
from Experiments
where platform = 'Android'
  and experiment_name = 'Programming'
union all
select 'IOS' as platform, 'Reading' as experiment_name, ifnull(count(*), 0) as num_experiments
from Experiments
where platform = 'IOS'
  and experiment_name = 'Reading'
union all
select 'IOS' as platform, 'Sports' as experiment_name, ifnull(count(*), 0) as num_experiments
from Experiments
where platform = 'IOS'
  and experiment_name = 'Sports'
union all
select 'IOS' as platform, 'Programming' as experiment_name, ifnull(count(*), 0) as num_experiments
from Experiments
where platform = 'IOS'
  and experiment_name = 'Programming'
union all
select 'Web' as platform, 'Reading' as experiment_name, ifnull(count(*), 0) as num_experiments
from Experiments
where platform = 'Web'
  and experiment_name = 'Reading'
union all
select 'Web' as platform, 'Sports' as experiment_name, ifnull(count(*), 0) as num_experiments
from Experiments
where platform = 'Web'
  and experiment_name = 'Sports'
union all
select 'Web' as platform, 'Programming' as experiment_name, ifnull(count(*), 0) as num_experiments
from Experiments
where platform = 'Web'
  and experiment_name = 'Programming'