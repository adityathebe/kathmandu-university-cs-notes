# Chapter 2 - Software Process Models

### Software Development Life Cycle

  "The period of time that starts when the product is conceived and ends when the product is no longer available for use" - **IEEE**
  
- *high-level, abstract descriptions of software processes*
- *is a simplified representation of software process ( the systematic approach that is used in software engineering )*
- *each process model represents a process from a particular perspective*
- *frameworks but not details of process activities*
  
1. Prescriptive Life cycle model
  A Prescriptive model prescribes how a new software system should be developed. Prescriptive models are used as a guidelines of frameworks to organize and structure how software development activites should be performed, and in what order. Typically, it is easier and more common to articulate a prescriptive lifecycle model for how system should be developed. This is possible since most such models are intuitive or well reasoned. This means that many idiosyncratic details that describes how a software system is built in practice can be ignored, generalized, or deferred for later consideration
2. Descriptive life cycle model
  Descriptive lifecycle models characterize how particular software systems are actually developed in specific settings. As such, they are less common and more difficult to articulate for an obvious reason: one must observe or collect data throughout the life cycle of a software system, a period of elapsed time often measured in years. Also, descriptive models are specific for the system observed and only generalized through systematic comparative analysis.

### Uses of software development process method

1. As a means to organize, plan, manage staffs, software projects, budgets and schedule.
2. As a perspective outline of the required set of documents to be produced
3. As a basis for determining which software engineering tools and methodology will be most appropriate.
4. As a framework for analyzing and estimating patterns of resource allocation and consumption during software life cycle
5. As a comparative descriptive or prescriptive accounts for how software system comes to be the way they are
6. As a basis for conducting imperial studies to determine what affects software productivity, cost and overall quality

### Software Engineering Approaches

1. Traditional / Classical Life cycle Model
2. Incremental
3. Integration and Configuration

#### 1. Waterfall model

![](https://proxy.duckduckgo.com/iu/?u=http%3A%2F%2F2.bp.blogspot.com%2F-m5mWrC94UHo%2FUGA0m1mvOuI%2FAAAAAAAAADc%2F6-d7MiaCZtk%2Fs1600%2Fwaterfall.gif&f=1)

**Stages**

1. Requirement Analysis and Specifications
2. Software and System design
3. Implementation and Unit Testing
4. Integration and System testing
5. Delivery and Maintenance

**Some problems encountered when Waterfall model is applied**

1. Real projects rarely follow the sequential flow that the model proposes. Changes can cause confusion as the project team proceeds.
2. It is often difficult for the customer to state all requirements explicitly. The waterfall model requires this and has difficulty accommodating the natural uncertainty that exists at the beginning of many projects.
3. The customer must have patience. A working version of the program(s) will not be available until late in the project time span. A major blunder, if undetected until the working program is reviewed, can be disastrous.
4. Linear nature of the classic life cycle leads to “blocking states” in which some project team members must wait for other members of the team to complete dependent tasks.

#### 2. Incremental Development

> Every increment must be delivered to the customer. As a result, the customer/users give feedback about what they want in the software. Sometimes this is an extra feature and functionality (scope creep!) and sometimes it is about removing things that were requested (scope retreat!). I call this incremental because the customers/users/stakeholders are seeing the thing grow in increments -- and hopefully early value is being delivered. 

An incremental model combines elements of the linear sequential model with the iterative phisophy of prototyping. The incremental model applies linear sequences in a staggered fashion as calendar time progresses. Each linear sequences produces a deliverable "increment" of the software.

![](https://3.bp.blogspot.com/-qh2Fi-p3BLM/UPR2Tc0YfeI/AAAAAAAABDU/cXeSWD78vok/s640/software_engineering_12.png)

There are many situations in which initial software requirements are reasonably well defined, but the overall scope of the development effort precludes a purely linear process. In addition, there may be a compelling need to provide a limited set of software functionality to users quickly and then refine and expand on that functionality in later software releases. In such cases, you can choose a process model that is designed to produce the software in increments.

When an incremental model is used, the first increment is often a core product. That is, basic requirements are addressed but many supplementary features (some known, others unknown) remain undelivered. The core product is used by the customer (or undergoes detailed evaluation). As a result of use and/or evaluation, a plan is developed for the next increment. The plan addresses the modification of the core product to better meet the needs of the customer and the delivery of additional features and functionality. This process is repeated following the delivery of each increment, until the complete product is produced.

Example, word-processing software developed using the incremental paradigm might deliver basic fi le management, editing, and document production functions in the fi rst increment; more sophisticated editing and document production capabilities in the second increment; spelling and grammar checking in the third increment; and advanced page layout capability in the fourth increment.

**2.1 Three Major advantages**
- Cost of changes is reduced
- Early feedbacks
- Early delivery and deployment

**2.2 Problems from a management perspective**
- Process is not visible
- System structure tends to degrade as new increments are added

#### 3. Evolutionary Process

> Evolutionary iterative development implies that the requirements, plan, estimates, and solution evolve or are refined over the course of the iterations, rather than fully defined and “frozen” in a major up-front specification effort before the development iterations begin. Evolutionary methods are consistent with the pattern of unpredictable discovery and change in new product development

**Evolutionary development focuses on early delivery of high value to stakeholders and on obtaining and utilizing feedback from stakeholders**

The intent of evolutionary models is to develop high-quality software in an iterative or incremental manner. However, it is possible to use an evolutionary process to emphasize flexibility, extensibility, and speed of development. The challenge for software teams and their managers is to establish a proper balance between these critical project and product parameters and customer satisfaction (the ultimate arbiter of software quality).

**Drawbacks**

- **Evolutionary software processes should be focused on flexibility and extensibility rather than on high quality. This assertion sounds scary.**
- Prototyping [and other more sophisticated evolutionary processes] poses a problem to project planning because of the uncertain number of cycles required to construct the product...
- Evolutionary software processes do not establish the maximum speed of the evolution. If the evolutions occur too fast, without a period of relaxation, it is certain that the process will fall into chaos. On the other hand if the speed is too slow then productivity could be affected...

* * *

### Agile Development

- Practically impossible to derive a complete set of stable software requirements.
- Best suited for application development where the system requirements usually change rapidly during the development process.
- Rapid software development and delivery is the most critical requirement for most business systems.
- Many businesses are willing to trade off software quality if they can deploy essential new software quickly

Based on the 2007 Pragmatic Institute Survey, the most common agile methods are
- Scrum
- Extreme Programming ( *1996* )
- RAD

**Values of Agile Methods**

1. Working software over comprehensive documents
2. Customer Involvement of contract negotiation
3. People and interaction over process and tools
4. Respond to change over following plan

**Agile Principles**

> Our 
> Business 
> Promote sustainable development.
> 
> we Welcome 
> Motivated individuals who love 
> Face-to-face conversation 
> and Adjust behavior
> 
> Simplicity and 
> Deliver frequently
> Working software 

![](https://publichealthmatters.blog.gov.uk/wp-content/uploads/sites/33/2016/07/AGILE-MANIFESTO.png)

**Politics of Agile Development**

Politics is the process by which groups of people make decisions. In business, the process for building products requires hundreds of decisions every week. There'll be a competition between marketing team and development team on having the control over the product. The challenge lies in 
- who is involved
- how are decisions made
- when should the decisions be made
- and who has the final authority.

**Key traits of people on an Agile team**

1. Competence
2. Common Focus
3. Collaboration
4. Fuzzy problem solving ability
5. Decision making ability
6. Mutual Trust and Respect
7. Self-organization

* * *

### Extreme Programming (XP)

- requirements are expressed as scenarios - User Stories
- programmers work in pairs and develop tests for each task before writing the code
- all tests must pass before integrating into the main system

**Most important practises**

1. **User Stories**
  User story is a scenario of use that might be experienced by a system user. Customer and the development team work closely to develop a story card that briefly describes a story that encapsulates the customer needs. The dev team then aims to implement that in a future release. Once the story cards have been developed, the dev team breaks them down into tasks and estimates the effort and resources required for implementing each tasks. The customer then prioritizes the stories for implementation. Riskiest stories are chosen first. As requirements change, the unimplemented stories change or may be discarded. The principle problem with user stories is completeness. It is difficult to judge - if a single story gives a true picture of an activity and if enough user stories have been developed to cover all of the essential requirements.
2. **Test Driven Development**
3. **Pair Programming**
4. **Refactoring**

**XP Values**

1. Communitcation
2. Simplicity
3. Feedback
4. Courage
5. Respect

### Industrial Extreme Programming (IXP)

**XP vs IXP**

* * *

### Scrum

**Three distinct roles**
- Product Owner
- ScrumMaster and
- Dev team members.

**5 Framework Activities**
1. Requirement
2. Analysis
3. Design
4. Evolution
5. Delivery

**Development Actions**
1. Backlog
  The product backlog is an ordered list of **everything that might be needed in the product** and is the **single source of requirements** for any changes to be made to the product. It contains - User Stories, Technical Requirements, Bugs,
3. Sprint
4. Meetings
5. Demos

**Four prescribed meetings in Scrum**
1. Sprint planning meeting
2. Daily standup
3. Sprint review
4. Sprint retrospective

**XP vs Scrum**

1. Development Cycles
Scrum teams typically work in iterations (called sprints) that can be two weeks to one month long. XP teams typically work in iterations that are one or two weeks long, the reason being XP believes in faster releases and quicker feedback.

2. Scope of Change
XP is flexible enough to accommodate changes in requirement/approach during the iteration, and believes in encouraging changes early in the game to deliver a quality product. As long as the team has not started working on a particular feature, it can be replaced for a new feature of the same complexity. Scrum on the other hand does not allow changes during the current sprint once the planning for that sprint is done. If any big change is necessary, the team can stop the current sprint and start a new sprint with new requirement.

3. Task Prioritisation
XP teams work in a strict order prioritised by the customer and the team is required to work on it in the same order. In contrast, the Product Owner in Scrum specifies the priority of development tasks in a sprint but the team still develops in the order they chose to, within a sprint.

4. Engineering Practices
XP strongly encourages team to use practices like pair programming, test driven development, refactoring, continuous integration and automated testing to improve quality, get frequent feedback from the customer & deliver in smaller releases. Scrum mainly focuses on productivity and does not prescribe any engineering practices but the team can adopt practices from XP or Kanban as per their project needs.

5. Product Owner
In XP the customer plays the role of Product Owner who is always available to the team to set the priority of tasks, bring in new requirements and review the frequent releases. In Scrum, the Scrum Master communicates to the Product Owner to set the stories in order for the sprint from the backlog. S/He also makes sure that the team understands each of the stories during the planning phase. Both of the above Agile methodologies aim to deliver the customer a quality product. After going through all the comparisons between XP and Scrum, I am sure you will be able to find the most suitable one for your project context. Let me know in the comments below which one you prefer more or maybe mix of both.

