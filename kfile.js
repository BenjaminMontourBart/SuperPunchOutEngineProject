let project = new Project("Punch Out");

await project.addProject("./TheEngine");

project.addFile("PunchOut/**");
project.addIncludeDir("./PunchOut/includes");

project.setDebugDir("Deployment");

project.flatten();

resolve(project);